#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;

#define sqr(x) ((x)*(x))

double ans;
long long n,t1,t2,t,x2,x1,ay1,ay2;
const double eps=1e-6;

void check(long long y2,long long y1){ 
        double ans1;
        if (y1+y2==0) ans1=0; else {
                ans1=(t1*y1+t2*y2);
                ans1/=(y1*1.0+y2*1.0)*1.0;
        }
        if ((abs(t-ans1)-abs(t-ans)<0 && ans1-t>=0)||(ans-t<0 && ans1-t>=0)||(ans1==ans && y1+y2>ay1+ay2)) {
                ans=ans1;
                ay1=y1;
                ay2=y2;
        }
}

int main() {

#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);       
        freopen("output.txt", "w", stdout);
#endif

        cin >> t1 >> t2 >> x1 >> x2 >> t;
        ans=-1;
		if (t==t1 && t==t2) cout << x1 << ' ' << x2; else
		if (t==t2) cout << 0 << ' ' << x2; else
		if (t==t1) cout << x1 << ' ' << 0;  else {
        for (long long y1=0; y1<=x1; y1++) {
                if (y1==99) 
                        y1=y1;
                double p;
                p=y1*(t1-t); p/=(t-t2)*1.0;
                if (p<0) p=0;
                if (p>x2) p=x2;
				if (y1==0) p=x2;
				if (p<eps) y1=x1;
                if (true) {
                        check(int(p),y1);
                        if (int(p)+1<=x2) check(int(p)+1,y1);
                }
        }
		cout << ay1 << ' ' << ay2;
		}
        return 0;
}