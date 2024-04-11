
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define MAXN 512345
#define INF INT_MAX
#define int long long
#define double long double
#define pii pair<int,int>
#define f first
#define s second
#define eps 1e-11
#define pi acos(-1)

bool rev(int a, int b){
    return a>b;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
    
    int n,m,k;
    cin>>n>>m>>k;
    int last=-1;
    vector<int> sizes;
    int ff=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(last!=-1)sizes.pb(x-last-1);
        else ff=x;
        last=x;
    }
    sort(sizes.begin(),sizes.end(),rev);
    k--;
    //cout<<k<<endl;
    int resp=last-ff+1;
    //cout<<resp<<endl;
    for(int i=0;i<min((int)sizes.size(),k);i++)resp-=sizes[i];
    cout<<resp<<endl;

    return 0;
 
}