#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
#define f first 
#define s second 
#define mp make_pair 

using namespace std;

priority_queue < pair < int , int> > q;
vector < pair < int ,int > > v[123];
int c[123],ans,b[123456],a[123567],n,x,y,m=1234567890;

int main(){
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i]>>b[i];
        if (b[i]<m) {m=b[i]; ans+=m*a[i]; } else ans+=m*a[i];    
            
        
    }
    cout<<ans;


    return 0;
    
}