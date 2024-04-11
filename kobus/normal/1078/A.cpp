#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define eps 1e-3
#define f first
#define s second
#define MAXN 512345
#define INF LLONG_MAX/4
#define double long double

double sq(double x1){return x1*x1;}

double dis(double x1,double y1,double x2,double y2){
    return sqrt(sq(x1-x2)+sq(y1-y2));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int a,b,c;
    cin>>a>>b>>c;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(a==0 || b==0){
        cout<<(double)1.*abs(x1-x2)+abs(y1-y2)<<endl;
        return 0;
    }
    double d11,d12,d21,d22;
    d11=dis(x1,y1,x1,-1.*(a*x1+c)/b);
    d12=dis(x1,y1,-1.*(b*y1+c)/a,y1);
    d21=dis(x2,y2,x2,-1.*(a*x2+c)/b);
    d22=dis(x2,y2,-1.*(b*y2+c)/a,y2);
    //cout<<d11<<" "<<d12<<" "<<d21<<" "<<d22<<endl;
    double resp=d11+d21+dis(x1,-1.*(a*x1+c)/b,x2,-1.*(a*x2+c)/b);
    resp=min(resp,d11+d22+dis(x1,-1.*(a*x1+c)/b,-1.*(b*y2+c)/a,y2));
    resp=min(resp,d12+d22+dis(-1.*(b*y1+c)/a,y1,-1.*(b*y2+c)/a,y2));
    resp=min(resp,d12+d21+dis(-1.*(b*y1+c)/a,y1,x2,-1.*(a*x2+c)/b));
    resp=min(resp,(double)1.*abs(x1-x2)+abs(y1-y2));
    cout<<resp<<endl;
    
}