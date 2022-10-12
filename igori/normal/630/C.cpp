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
    long long t=0;
    cin>>t;
    long long ans=0;
    long long b=1;
    for(int i=0; i<t; i++)
    {
        b=b*2;
        ans+=b;
    }
    cout<<ans;
}