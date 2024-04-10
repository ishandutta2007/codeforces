#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>

#define ll long long
#define mp make_pair
#define f first
#define s second

using namespace std;

const int MOD = (int)(1e9) + 7;
int n,a[123456],b[123456],z;
map<ll,int> M;
set<int> S;

int main(){
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    if (n==1) {
        cout<<-1;
        return 0;
    }
    
    for (int i=1; i<n; i++) {
        S.insert(a[i]-a[i-1]);  
        M[a[i]-a[i-1]]++;   
    }
    for (set<int>::iterator it=S.begin(); it!=S.end(); it++) 
        b[z++]=(*it);                                       
    if (z==1 && b[0]==0) {
        cout<<1<<endl;
        cout<<a[0];
        return 0;
    }
    if (z==1) {
        if (n==2) {
            int t=a[1]-a[0];
            if ((a[1]-a[0])%2==0) {
                cout<<3<<endl;  
                cout<<a[0]-t<<" "<<a[0]+(t/2)<<" "<<a[1]+t;
                return 0;
            }   else {
                cout<<2<<endl;
                cout<<a[0]-t<<" "<<a[1]+t;
                return 0;
            }
        }

        cout<<2<<endl;
        cout<<a[0]-b[0]<<" "<<a[n-1]+b[0]; 
        return 0;
    }

    if (z==2 && b[1]==b[0]*2 && M[b[1]]==1) {
        cout<<1<<endl;
        for (int i=1; i<n; i++)
            if (a[i]-a[i-1]==b[1]) {
                cout<<a[i-1]+b[0];
                return 0;
            }
    
    }
    cout<<0;
    
    
    


    return 0;
}