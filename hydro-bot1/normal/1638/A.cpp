// Hydro submission #620b3ece6933527d089d7bf2@1644943048405
#include<set>
#include<map>
#include<list>
#include<cmath>
#include<stack>
#include<queue>
#include<array>
#include<bitset>
#include<cstdio>
#include<vector>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<functional>
#include<unordered_map>
#include<unordered_set>

#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define PLL pair<ll,ll>
#define PII pair<int,int>
#define PSI pair<string,int>
#define PIS pair<int,string>

using namespace std;

const int MAXN=5e2+5,INF=0x7fffffff;
const double EPS=1e-6,PI=acos(-1.0);

int T,n;
array<int,MAXN> arr;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--){

        cin>>n;
        for(int i=1;i<=n;i++) cin>>arr[i];

        int l=1;
        while(arr[l]==l && l<=n) l++;

        if(l>n){
            for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
            cout<<endl;

            continue;
        }

        int r=l+1;
        while(arr[r]!=l) r++;

        for(int i=1;i<l;i++) cout<<arr[i]<<" ";
        for(int i=r;i>=l;i--) cout<<arr[i]<<" ";
        for(int i=r+1;i<=n;i++) cout<<arr[i]<<" ";
        cout<<endl;

    }

    return 0;
}