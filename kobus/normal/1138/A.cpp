#include <bits/stdc++.h>
using namespace std;
#define INF 1'000'000'000'010
#define double long double
#define f first
#define s second
#define eps 1e-11
#define pb push_back

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(5);
    cout.setf(ios::fixed);

    int n;
    cin>>n;
    vector<int> v;
    int last=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(last==0||last!=x){
            v.pb(1);
            last=x;
        }
        else v[v.size()-1]++;
    }
    int resp=0;
    for(int i=0;i<v.size()-1;i++){
        resp=max(resp,min(v[i],v[i+1]));
    }
    cout<<2*resp<<endl;

    return 0;
}