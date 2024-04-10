#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5+4;
int N;
string s[NS];
int cnt[NS*10], ccnt;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=1;i<=N;++i) cin >> s[i];
    for(int i=1;i<=N;++i){
        int A = 0, B = 0;
        for(int j=0;j<(int)s[i].size();++j){
            if(s[i][j]=='(') ++A;
            else{
                if(A>0) --A;
                else ++B;
            }
        }
        if(A&&!B) ++cnt[A];
        else if(!A&&B) ++cnt[B+NS*5];
        else if(!A&&!B) ++ccnt;
    }
    int ans = 0;
    for(int i=0;i<=NS*5;++i) ans += min(cnt[i], cnt[i+NS*5]);
    cout << ans+ccnt/2;

    return 0;
}