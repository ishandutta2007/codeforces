#pragma GCC Optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
//#define endl '\n'
const int N = 1007;
const int AL = 26;
char A[N];
int pos[AL];
char ask1(int pos){
    cout<<"? 1 "<<pos<<endl;
    char ch;
    cin>>ch;
    return ch;
}
int ask2(int l,int r){
    cout<<"? 2 "<<l<<' '<<r<<endl;
    int ret;
    cin>>ret;
    return ret;
}
void solve(){
    int n;
    cin>>n;

    for(int i = 1;i<=n;i+=1){
        vector<pair<int,char> > ps;
        for(int s = 0;s<AL;s+=1){
            if (pos[s]!=0){
                ps.push_back({pos[s],char('a'+s)});
            }
        }
        sort(ps.begin(),ps.end(),greater<pair<int,char>>());
        int l = 0,r = ps.size();
        while(l!=r){
            int mid = (l+r)/2;
            if (ask2(ps[mid].first,i)==mid+2){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        if (l==ps.size()){
            A[i] = ask1(i);
        }
        else{
            A[i] = ps[l].second;
        }
        pos[A[i]-'a'] = i;
    }
    cout<<"! ";
    for(int i = 1;i<=n;i+=1){
        cout<<A[i];
    }
    cout<<endl;
}
signed main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}