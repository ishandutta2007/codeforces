#include <bits/stdc++.h>
#define NMAX (int)(1e4+4)
#define MOD (int)(1e9+7)
#define pb push_back
#define ft first
#define sd second
using namespace std;
typedef pair <int, int> pairINT;
typedef long long ll;
 
ll q,x,sol,l,cnt;
string s,aux;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>q;
    while(q--){
        cin>>x>>s;
        l=0;
        sol=s.size();
        while(l!=x){
            ++l;
            cnt=s[l-1]-'1';
            sol=(sol + ((sol-l)*cnt + MOD)%MOD)%MOD;
            if(s.size()<=x){
                int sz = s.size() - l;
                for(int i=0;i<cnt && s.size()<=x;++i)
                    s += s.substr(l, sz);
                    // s.append(aux);
            }
        }
        cout<<sol<<'\n';
    }
    return 0;
}