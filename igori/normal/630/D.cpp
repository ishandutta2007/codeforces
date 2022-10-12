#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <sstream>

#define NO "NO"
#define YES "YES"
#define forn(n) for(int i=0; i<(n); i++)
#define pb push_back
#define sz size()
#define IgorI_sollution int main()
#define std_v(N) long long n,k,l,h,ans; int a[(N)],b[(N)],m[(N)]; string s; vector<int> v;
#define I i++

using namespace std;



int main()
{
    long long n;
    long long ans=0;
    cin>>n;

    ans=((n+1+2*n+1)*(n+1))/2;
    ans+=((n+1+2*n)*n)/2;
    cout<<ans;
}