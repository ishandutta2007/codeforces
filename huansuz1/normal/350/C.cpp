#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#define pb push_back
#define mk make_pair
#define inf  (1ll << 55)
#define f first
#define s second
#define MAXN (1 << 20)
#define ll long long;

using namespace std;

int xa, xb, ya, yb;
int x[123456],y[123456],n,ans;
pair<int,int> c[123456];
int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d%d",&x[i],&y[i]);
        c[i].f=abs(x[i])+abs(y[i]);    
        c[i].s = i;
    }

    sort(c, c + n);

    for (int i = 0; i < n; i++) {
        int xx = x[c[i].s];
        int yy = y[c[i].s];
        if (xx>0 && yy>0) {
            ans+=6;
        } else 
        if (xx<0 && yy>0) {
            ans+=6;
        } else 
        if (xx>0 && yy<0) {
            ans+=6;
        } else 
        if (xx<0 && yy<0) {
            ans+=6;
        } else
        if (xx==0 && yy>0) {
            ans+=4;
        } else  
        if (xx==0 && yy<0) {
            ans+=4;
        } else 
        if (xx>0 && yy==0) {
            ans+=4;
        } else  
        if (xx<0 && yy==0) {
            ans+=4;
        } 

    }
    cout<<ans<<endl;
    for (int i = 0; i < n; i++) {
        int xx = x[c[i].s];
        int yy = y[c[i].s];
        if (xx>0 && yy>0) {
            printf("%d %d %s\n",1,xx,"R");
            printf("%d %d %s\n",1,yy,"U");
            printf("%d\n",2);
            printf("%d %d %s\n",1,xx,"L");
            printf("%d %d %s\n",1,yy,"D");
            printf("%d\n",3);
        } else 
        if (xx<0 && yy>0) {
            printf("%d %d %s\n",1,abs(xx),"L");
            printf("%d %d %s\n",1,yy,"U");
            printf("%d\n",2);
            printf("%d %d %s\n",1,abs(xx),"R");
            printf("%d %d %s\n",1,yy,"D");
            printf("%d\n",3);
        } else 
        if (xx>0 && yy<0) {
            printf("%d %d %s\n",1,xx,"R");
            printf("%d %d %s\n",1,abs(yy),"D");
            printf("%d\n",2);
            printf("%d %d %s\n",1,xx,"L");
            printf("%d %d %s\n",1,abs(yy),"U");
            printf("%d\n",3);
        } else 
        if (xx<0 && yy<0) {
            printf("%d %d %s\n",1,abs(xx),"L");
            printf("%d %d %s\n",1,abs(yy),"D");
            printf("%d\n",2);
            printf("%d %d %s\n",1,abs(xx),"R");
            printf("%d %d %s\n",1,abs(yy),"U");
            printf("%d\n",3);
            } else
        if (xx==0 && yy>0) {
            printf("%d %d %s\n",1,yy,"U");
            printf("%d\n",2);
            printf("%d %d %s\n",1,yy,"D");
            printf("%d\n",3);
        } else  
        if (xx==0 && yy<0) {
            printf("%d %d %s\n",1,abs(yy),"D");
            printf("%d\n",2);
            printf("%d %d %s\n",1,abs(yy),"U");
            printf("%d\n",3);
        } else 
        if (xx>0 && yy==0) {
            printf("%d %d %s\n",1,xx,"R");
            printf("%d\n",2);
            printf("%d %d %s\n",1,xx,"L");
            printf("%d\n",3);
        } else  
        if (xx<0 && yy==0) {
            printf("%d %d %s\n",1,abs(xx),"L");
            printf("%d\n",2);
            printf("%d %d %s\n",1,abs(xx),"R");
            printf("%d\n",3);
        } 

    }



    
    return 0;
}