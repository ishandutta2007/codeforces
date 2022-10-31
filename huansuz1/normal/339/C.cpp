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

string s;
int m,p,n,a[1234],z,x,y,q,w,b[12345],qw;


int main(){   
    cin>>s>>m;
    for (int i=0; i<s.length(); i++){
        if (s[i]=='1') a[z++]=i+1;  
    }

    for (int we=0; we<z; we++){
        
        q=1;
        b[q]=a[we];
        int p=a[we];
        x=p;
        y=0;
        int ew=0;

        while(q!=m){
            q++;
            if (q%2==1) {
                w=0;
                for (int i=0; i<z; i++)
                    if (a[i]!=p && x+a[i]>y) {
                        x+=a[i];
                        p=a[i];
                        b[q]=a[i];
                        w=1; 
                        break;
                    }
            } else {
                w=0;
                for (int i=0; i<z; i++)
                    if (a[i]!=p && y+a[i]>x) {
                        y+=a[i];
                        p=a[i];
                        b[q]=a[i];
                        w=1; 
                        break;
                    }
            }
            ew+=w;

        }

        if (q==m && ew==m-1) {
             cout<<"YES"<<endl;
            for (int i=1; i<=q; i++) 
             cout<<b[i]<<" ";
            return 0;
        }


      }
      cout<<"NO";





    return 0;



}