#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
//#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 2123456
#define INF LLONG_MAX
#define MOD 999999599
#define cte 10002
#define MAX 21234

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int n;
    cin>>n;
    int resp=0;
    int posx=0,posy=0;
    int kgd=-1;
    int lkgd=-1;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        lkgd=kgd;
        if(c=='U')posy++;
        else posx++;
        if(posy>posx)kgd=1;
        if(posx>posy)kgd=0;
        if(lkgd!=-1 && lkgd!=kgd)resp++;
        //cout<<posx<<" "<<posy<<" "<<kgd<<endl;
    }
    cout<<resp<<endl;

    return 0;

}