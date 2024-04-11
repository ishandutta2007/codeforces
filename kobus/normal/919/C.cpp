#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 212
#define INF LLONG_MAX
#define MOD 999999599
#define cte 10002
#define MAX 21234

char m[2123][2123];
char aux[2123][2123];
int l,c,k;


int go(){
    int resp=0;
    for(int i=0;i<l;i++){
        int num=0;
        for(int j=0;j<c;j++){
            if(m[i][j]=='.')num++;
            else{
                resp+=max(0ll,num-k+1);
                num=0;
            }
            //cout<<num<<endl;
        }
        resp+=max(0ll,num-k+1);
        //cout<<resp<<endl;
    }
    return resp;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    cin>>l>>c>>k;

    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            cin>>m[i][j];
        }
    }

    int resp=0;
    resp+=go();

    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            aux[j][i]=m[i][j];
        }
    }
    swap(l,c);
    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            m[i][j]=aux[i][j];
        }
    }

    resp+=go();

    if(k==1)resp=resp/2;
    cout<<resp<<endl;

    return 0;

}