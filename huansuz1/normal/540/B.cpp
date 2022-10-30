    #include <algorithm>
    #include <iostream>
    #include <cstring>
    #include <cstdlib>
    #include <string>
    #include <cstdio>
    #include <cmath>
    #include <map>
    #include <set>
    #include <queue>
    #define f first
    #define s second
    #define mp make_pair
    #define ll long long
     
    using namespace std;
    int n,h,m,c,h1,m1,c1,a,b[1234],d[1234];
    
    int q,k,p,x,y;
    string t,s;
    int main(){
    cin>>n>>k>>p>>x>>y;
    for (int i=0; i<k; i++){
        cin>>c;
        d[i]=c;
        q+=c;
    }
    if (q>x) {cout<<-1; exit(0);}
    a=x-q;
    int z=0,t=0;
    while(z!=-1){
        b[z]++;
        t++;
        z++;
        if (t==a) break;
        if (z==n-k) {
            for (int i=0; i<n-k; i++) {
                b[i]=y;                
                t+=y-1;
                if (t>a) {
                    while(t>a){
                        t--;
                        b[i]--;
                    }
                    break;
                }
            }
            break;
        }
    }   
    for (int i=k; i<n; i++) 
        d[i]=b[i-k];
        
    sort(d,d+n);
        if (d[n/2]<y|| d[0]==0) {cout<<-1; exit(0);} 
        for (int i=0; i<n-k; i++)
            cout<<b[i]<<" ";

    
    
    
    }