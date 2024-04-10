#include<bits/stdc++.h>
typedef long long ll;
ll a,b,c;
struct point {
    ll x,y;
    point(){}
    point(const ll &_x,const ll &_y) {
        x=_x;y=_y;
    }
};
ll abs(const ll &x) {
    if (x<0) return (-x); else return (x);
}
ll mod(const ll &a,const ll &b) {
    if (b<0) return (mod(-a,-b));
    if (a<0) return (-mod(-a,b));
    return (a%b);
}
ll div(const ll &a,const ll &b) {
    if (b<0) return (div(-a,-b));
    if (a<0) return (-div(-a,b));
    return (a/b);
}
ll gcd(ll a,ll b) {
    if (a<0) return (gcd(-a,b));
    if (b<0) return (gcd(a,-b));
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a%b==0) return (b);
        if (b%a==0) return (a);
        if (a>b) a=a%b;         
        else b=b%a;     
    }   
}
point solve(ll a,ll b,ll c) {
    //printf("Solving %I64d %I64d %I64d\n",a,b,c);
    point ret,tmp;
    ll d=gcd(a,b);
    //printf("123\n");
    if (mod(c,d)!=0) {
        printf("-1");
        exit(0);
    }
    //printf("123\n");
    a=div(a,d);b=div(b,d);c=div(c,d);
    //printf("123\n");
    if (abs(a)<=abs(b)) {
        if (a<0) {
            a=-a;b=-b;c=-c;
        }
        if (a==1) return (point(c,0));
        tmp=solve(a,mod(b,a),mod(c,a));
        ret.x=tmp.x+div(c,a)-div(b,a)*tmp.y;
        ret.y=tmp.y;
        return (ret);
    }
    if (abs(a)>abs(b)) {
        if (b<0) {
            a=-a;b=-b;c=-c;
        }
        if (b==1) return (point(0LL,c));
        tmp=solve(mod(a,b),b,mod(c,b));
        ret.x=tmp.x;
        ret.y=tmp.y+div(c,b)-div(a,b)*tmp.x;
        return (ret);
    }
}
void process(void) {
    scanf("%I64d",&a);
    scanf("%I64d",&b);
    scanf("%I64d",&c);
    if (a==0) {
        if (mod(c,b)==0) printf("%I64d %I64d",0LL,div(-c,b));
        else printf("-1");
        exit(0);
    }
    if (b==0) {
        if (mod(c,a)==0) printf("%I64d %I64d",div(-c,a),0LL);
        else printf("-1");
        exit(0);
    }
    point res=solve(a,b,-c);
    printf("%I64d %I64d",res.x,res.y);
}
int main(void) {
    process();
    return 0;
}