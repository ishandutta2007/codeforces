#include <bits/stdc++.h>

using namespace std;

int main()
{int n,m,a;
cin>>n>>m>>a;

unsigned long long r=ceil(n/(a+0.0))*ceil(m/(a+0.0));
    cout << r << endl;
    return 0;
}