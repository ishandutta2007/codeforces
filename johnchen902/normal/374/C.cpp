#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


const int max_size = 1000;
const int infinity = max_size * max_size + 1;
const int unsearched = -1;
const int instack = -2;

int w, h;
int dp[max_size][max_size];
char map[max_size][max_size];

char next(char c){
    switch(c){
    case 'D': return 'I';
    case 'I': return 'M';
    case 'M': return 'A';
    case 'A': return 'D';
    }
    return '\0';
}

struct S{
    int x, y, d, r;
    S(int a, int b):x(a),y(b),d(0),r(0){}
};

int dfs(int initx, int inity){
    stack<S> st;
    st.push(S(initx, inity));
    int return_value = 0;
    while(!st.empty()){
        S &s = st.top();
        switch(s.d++){
        case 0:
            if(dp[s.x][s.y] == instack){
                return_value = infinity;
                st.pop();
            } else if(dp[s.x][s.y] != unsearched){
                return_value = dp[s.x][s.y];
                st.pop();
            } else {
                dp[s.x][s.y] = instack;
                return_value = 0;
                if(s.x > 0 && map[s.x-1][s.y] == next(map[s.x][s.y]))
                    st.push(S(s.x-1, s.y));
            }
            break;
        case 1:
            s.r = max(s.r, return_value);
            if(s.y > 0 && map[s.x][s.y-1] == next(map[s.x][s.y]))
                st.push(S(s.x, s.y-1));
            break;
        case 2:
            s.r = max(s.r, return_value);
            if(s.x + 1 < w && map[s.x+1][s.y] == next(map[s.x][s.y]))
                st.push(S(s.x+1, s.y));
            break;
        case 3:
            s.r = max(s.r, return_value);
            if(s.y + 1 < h && map[s.x][s.y+1] == next(map[s.x][s.y]))
                st.push(S(s.x, s.y+1));
            break;
        case 4:
            s.r = max(s.r, return_value);
            return_value = dp[s.x][s.y] = s.r + 1;
            st.pop();
            break;
        }
    }

//    if(dp[x0][y0] == instack)
//        return infinity;
//    if(dp[x0][y0] != unsearched)
//        return dp[x0][y0];
//    dp[x0][y0] = instack;
//    int max0 = 0;
//    if(x0 > 0 && map[x0-1][y0] == next(map[x0][y0]))
//        max0 = max(max0, dfs(x0-1, y0));
//    if(y0 > 0 && map[x0][y0-1] == next(map[x0][y0]))
//        max0 = max(max0, dfs(x0, y0-1));
//    if(x0 + 1 < w && map[x0+1][y0] == next(map[x0][y0]))
//        max0 = max(max0, dfs(x0+1, y0));
//    if(y0 + 1 < h && map[x0][y0+1] == next(map[x0][y0]))
//        max0 = max(max0, dfs(x0, y0+1));
//    return dp[x0][y0] = max0 + 1;
    return return_value;
}

int main() {
    cin >> h >> w;
    for(int y = 0; y < h; y++)
        for(int x = 0; x < w; x++){
            cin >> map[x][y];
            dp[x][y] = unsearched;
        }
    int len = 0;
    for(int x = 0; x < w; x++)
        for(int y = 0; y < h; y++)
            if(map[x][y] == 'D')
                len = max(len, dfs(x, y));
    if(len >= infinity)
        cout << "Poor Inna!" << endl;
    else if(len / 4 == 0)
        cout << "Poor Dima!" << endl;
    else
        cout << len / 4 << endl;
    return 0;
}