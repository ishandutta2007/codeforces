#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T>
istream &operator >> (istream &in, vector<T> &v) {
    for (auto &i : v) {
        in >> i;
    }
    return in;
}

template<class T>
ostream &operator << (ostream &out, const vector<T> &v) {
    for (auto &i : v) {
        out << i << ' ';
    }
    return out;
}

int main() {

    long double a,b,c;
    cin >> a >> b >> c;
    long double  x,y,x1,y1;
    cin >> x >> y >> x1 >> y1;
    long double s,s1,k,k1,co,co1,co2;
    s=abs(y-(-c-a*x)/b);
    s1=abs(x-(-c-b*y)/a);
    k=abs(y1-(-c-a*x1)/b);
    k1=abs(x1-(-c-b*y1)/a);


    long double ans1=abs(x-x1)+abs(y-y1);
    long double ans2=min(ans1,s+sqrt(((-c-a*x)/b-y1)*((-c-a*x)/b-y1)+(x-(-c-b*y1)/a)*(x-(-c-b*y1)/a))+k1);
    long double ans3=min(ans2,s+sqrt(((-c-a*x)/b-(-c-a*x1)/b)*((-c-a*x)/b-(-c-a*x1)/b)+(x-x1)*(x-x1))+k);
    long double ans4=min(ans3,s1+sqrt((y-y1)*(y-y1)+((-c-b*y)/a-(-c-b*y1)/a)*((-c-b*y)/a-(-c-b*y1)/a))+k1);
    long double ans=min(ans4,s1+sqrt((y-(-c-a*x1)/b)*(y-(-c-a*x1)/b)+((-c-b*y)/a-x1)*((-c-b*y)/a-x1))+k);

    cout << setprecision(9);
    cout << ans;




    return 0;
}