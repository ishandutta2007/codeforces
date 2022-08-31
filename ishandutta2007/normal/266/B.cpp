#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<queue>
#include <utility>
using namespace std;
set< pair <int , int > > count_element_pair;
map< int , int > elementcount;

int main()
{
    int n;scanf("%d",&n);
    int t;scanf("%d",&t);
    char st[n+2];scanf("%s",&st);
    for(int i=0;i<t;i++)
    {
     for(int j=0;j<n-1;j++)
     {
         if(st[j]=='B'&&st[j+1]=='G'){swap(st[j],st[j+1]);j++;}
     }
    }
    cout<<st<<endl;
    return 0;
}