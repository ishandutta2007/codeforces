#include <bits/stdc++.h>
using namespace std;

#define MAXN 1123456
#define int long long
#define pb push_back
#define inf INT_MAX
#define mp make_pair
#define pii pair<int,int>
#define f first
#define s second

string ans;


void find(int a,int b,int k){
    //cout<<a<<" "<<b<<" "<<k<<endl;
    if(a==0){
        for(int i=0;i<b;i++)ans.pb('b');
        return;
    }
    int ns;
    if(b==2)ns=(a)*(a+1)/2;
    if(b==1)ns=(a);
    if(b==0)ns=1;

    if(k>ns){
        ans.pb('b');
        find(a,b-1,k-ns);
    }
    else{
        ans.pb('a');
        find(a-1,b,k);
    }
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        ans.clear();
        int n,k;
        cin>>n>>k;
        find(n-2,2,k);
        cout<<ans<<endl;
    
    }
    return 0;
 
}