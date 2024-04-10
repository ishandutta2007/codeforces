// Hydro submission #61aad6a13db3dedd6b6f559a@1638586018676
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <list>
#include <deque>
#include <bitset>
#include <functional>
#include <limits>
#include <ios>
#include <istream>
#include <sstream>
#include <fstream>
#include <ostream>
#include <new>
#include <iosfwd>
#include <cassert>
#include <stdio.h>
#include <climits>
#include <ctime>
#include <memory>
#include <cwchar>
#include <strstream>
#include <locale>
#include <clocale>
#include <ciso646>
#include <cctype>
#include <cwctype>
#include <cerrno>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
#define NO {puts("-1");return;}
void solve()
{
    int ling,yi;
    cd(ling);
    cd(yi);
    string s;
    cin>>s;
    int n=ling+yi;
    int sum[2]={0,0};
    fi(i,0,n)
    {
        if(s[i]=='0')sum[0]++;
        else if(s[i]=='1')sum[1]++;
    }
    fi(i,0,n/2)
    {
        int j=n-i-1;//ij
        if(s[i]!='?'&&s[j]!='?')//'?'
        {
            if(s[i]!=s[j])//'?'
            {
                NO; 
            }
        }
        else if(s[i]=='?'&&s[j]=='?')//'?'
        {
			//
        }
        else //
        {
            if(s[i]=='?')//s[i]'?'
            {
                s[i]=s[j];//s[i]s[j]
                sum[s[j]-'0']++;//0++
            }
            else//s[j]'?'
            {
                s[j]=s[i];
                sum[s[i]-'0']++;
            }
        }
    }
    if(sum[0]>ling||sum[1]>yi)//0101
    {
        NO;//
    }
    if(n%2==0&&ling%2!=0)//n01
    {
        NO;
    }
    ling=ling-sum[0];//0
    yi=yi-sum[1];//1
    if(ling%2&&yi%2)//01
    {
        NO;//
    }
    if(ling%2)//01
    {
        if(s[n/2]!='?')//'?'
        {
            NO;
        }
        else//
        {
            s[n/2]='0';//0
            ling--;
        }
    }
    if(yi%2)//1
    {
        if(s[n/2]!='?')
        {
            NO;
        }
        else
        {
            s[n/2]='1';
            yi--;
        }
    }
    for(int i=0;i<n/2;i++)
    {
        int j=n-i-1;
        if(s[i]=='?'&&s[j]=='?')//'?'
        {
            if(ling)//0
            {
                ling-=2;
                s[i]=s[j]='0';//0
            }
            else//
            {
                yi-=2;
                s[i]=s[j]='1';//1
            }
        }
    }
    if(ling||yi)
    {
        NO;//
    }
    cout<<s<<endl;
    return;
}
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        solve();
    }
    return 0;
}