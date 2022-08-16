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
    char st[n+2];scanf("%s",&st);
    int i=0,s=0;
    while(i<n)
    {
        char c=st[i];
        i++;
        int l=0;
        while(st[i]==c){l++;i++;}
        s+=l;
    }
    cout<<s<<endl;
    return 0;
}