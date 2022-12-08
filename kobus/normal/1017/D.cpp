#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
#define double long double
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 1123456
#define INF LLONG_MAX
#define MOD 3241618756

int w[512345];
int val[512345];
int k[512345];
int freq[512345];
int freqm[5123][101];


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout.setf(ios::fixed);

    int n,q,m;
    cin>>n>>q>>m;

    for(int i=0;i<n;i++)cin>>w[i];

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<(1<<n);j++){
            if((j>>i)%2==1)val[j]+=w[n-i-1];
        }
    }

    for(int i=0;i<q;i++){
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            k[i]*=2;
            k[i]+=(c=='1');
        }
        freq[k[i]]++;
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<(1<<n);j++){
            int a=val[((1<<n)-1)^i^j];
            if(a<=100)
                freqm[i][a]+=freq[j];
        }
    }
    for(int i=0;i<m;i++){
        int valo=0;
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            valo*=2;
            valo+=(c=='1');
        }
        int ka;
        cin>>ka;
        int resp=0;
        for(int j=0;j<=ka;j++){
            resp+=freqm[valo][j];
        }
        cout<<resp<<endl;
    }


    return 0;
}