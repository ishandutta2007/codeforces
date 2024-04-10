#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;
 
int N , M;
char s[53][53] , t[53][53];
 
char getc(){
    char c = getchar();
    while(c == ' ' || c == '\n')
        c = getchar();
    return c;
}
 
#define PII pair < int , int >
vector < PII > stp;
void rotate(int x , int y){
    stp.push_back(PII(x , y));
    if(s[x][y] == 'L'){
        s[x][y] = s[x][y + 1] = 'U';
        s[x + 1][y] = s[x + 1][y + 1] = 'D';
    }
    else{
        s[x][y] = s[x + 1][y] = 'L';
        s[x][y + 1] = s[x + 1][y + 1] = 'R';
    }
}
 
void dfs(int x , int y){
    if(s[x][y] == 'L') return;
    if(s[x][y + 1] == 'L'){
        dfs(x + 1 , y + 1);
        rotate(x , y + 1); rotate(x , y);
    }
    else rotate(x , y);
}
 
vector < PII > change(){
    int n = N , m = M;
    if(M & 1){
        for(int i = 1 ; i <= N ; ++i)
            for(int j = 1 ; j <= M ; ++j)
                switch(s[i][j]){
                case 'U': t[j][i] = 'L'; break;
                case 'D': t[j][i] = 'R'; break;
                case 'L': t[j][i] = 'U'; break;
                case 'R': t[j][i] = 'D'; break;
                }
        memcpy(s , t , sizeof(t));
        swap(n , m);
    }
    stp.clear();
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j)
            if(s[i][j] == 'U') dfs(i , j);
    if(M & 1)
        for(auto &t : stp) swap(t.first , t.second);
    return stp;
}
 
int main(){
    cin >> N >> M;
    for(int i = 1 ; i <= N ; ++i)
        for(int j = 1 ; j <= M ; ++j)
            s[i][j] = getc();
    vector < PII > pre = change();
    for(int i = 1 ; i <= N ; ++i)
        for(int j = 1 ; j <= M ; ++j)
            s[i][j] = getc();
    vector < PII > nxt = change();
    cout << pre.size() + nxt.size() << endl;
    for(auto t : pre) cout << t.first << ' ' << t.second << endl;
    reverse(nxt.begin() , nxt.end());
    for(auto t : nxt) cout << t.first << ' ' << t.second << endl;
    return 0;
}