#include<bits/stdc++.h>
//This code is written by Itst
#define PII pair < int , int >
using namespace std;
inline int read(){
    int a = 0;
    char c = getchar();
    while(!isdigit(c))
        c = getchar();
    while(isdigit(c)){
        a = a * 10 + c - '0';
        c = getchar();
    }
    return a;
}
deque < PII > v1 , v2;
int N , M;
int ans;
inline int turn(int x){
    int sum = 0;
    for(int i = 0 ; i < 30 ; ++i)
        if(x & (1 << i))
            sum += 1 << (29 - i);
    return sum;
}
void solve(deque < PII > v1 , deque < PII > v2 , int cur){
    if(cur < 0 || v1.size() + v2.size() <= ans)
        return;
    deque < PII > p1 , p2 , p3 , p4;
    int L = 0 , R = v1.size();
    while(L < R){
        int mid = (L + R) >> 1;
        v1[mid].first & (1 << cur) ? R = mid : L = mid + 1;
    }
    if(v1.size() - L < L){
        while(v1.size() != L){
            p1.push_back(v1.back());
            v1.pop_back();
        }
        p2 = v1;
    }
    else{
        for(int i = 0 ; i < L ; ++i){
            p2.push_back(v1.front());
            v1.pop_front();
        }
        p1 = v1;
    }
    L = 0;
    R = v2.size();
    while(L < R){
        int mid = (L + R) >> 1;
        v2[mid].first & (1 << cur) ? R = mid : L = mid + 1;
    }
    if(v2.size() - L < L){
        while(v2.size() != L){
            p3.push_back(v2.back());
            v2.pop_back();
        }
        p4 = v2;
    }
    else{
        for(int i = 0 ; i < L ; ++i){
            p4.push_back(v2.front());
            v2.pop_front();
        }
        p3 = v2;
    }
    ans = max(ans , (int)max(p1.size() + p4.size() , p2.size() + p3.size()));
    solve(p1 , p3 , cur - 1);
    solve(p2 , p4 , cur - 1);
}
int main(){
    N = read();
    read();
    for(int i = 1 ; i <= N ; ++i){
        int a = read();
        v1.push_back(PII(turn(a) , a));
    }
    sort(v1.begin() , v1.end());
    M = read();
    read();
    for(int i = 1 ; i <= M ; ++i){
        int a = read();
        v2.push_back(PII(turn(a) , a));
    }
    sort(v2.begin() , v2.end());
    ans = !v1.empty() + !v2.empty();
    solve(v1 , v2 , 29);
    cout << ans;
    return 0;
}