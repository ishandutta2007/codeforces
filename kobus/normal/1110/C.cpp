
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

map<int,int> m;

int nxtpwr(int n){
    int k=1;
    while(k<=n){
        //cout<<"loop "<<k<<" "<<n<<endl;
        k*=2;
    }
    return k;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);
    
    m[0]=0;
m[1]=0;
m[3]=1;
m[7]=1;
m[15]=5;
m[31]=1;
m[63]=21;
m[127]=1;
m[255]=85;
m[511]=73;
m[1023]=341;
m[2047]=89;
m[4095]=1365;
m[8191]=1;
m[16383]=5461;
m[32767]=4681;
m[65535]=21845;
m[131071]=1;
m[262143]=87381;
m[524287]=1;
m[1048575]=349525;
m[2097151]=299593;
m[4194303]=1398101;
m[8388607]=178481;
m[16777215]=5592405;
m[33554431]=1082401;


    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        //cout<<x<<" "<<nxtpwr(x)<<endl;
        if(nxtpwr(x)==x+1)cout<<m[x]<<endl;
        else cout<<nxtpwr(x)-1<<endl;
    }

    return 0;
 
}