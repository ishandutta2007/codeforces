#include <bits/stdc++.h>
using namespace std;
int main()
{
double n, l;
cin >> n >> l;
vector<double> a(n);
for(int i = 0; i < n; ++i){
cin >> a[i];
}
sort(a.begin(), a.end());
double m = a[1] - a[0];
for(int i = 2; i < a.size(); ++i){
m = max(m, a[i] - a[i - 1]);
}
cout <<fixed<<setprecision(9)<<max(m/2., max(a[0], l-a[a.size()-1]));
return 0;
}