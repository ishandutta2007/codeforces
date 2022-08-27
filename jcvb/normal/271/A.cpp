#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<deque>
using namespace std;
int arr[10]={0};
int ok(int n){
    memset(arr,0,sizeof(arr));
    while(n){
             int tmp=n%10;
             arr[tmp]++;
             if(arr[tmp]>1)return 0;
             n/=10;
    }
    return 1;
}
    
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=n+1;;i++)if(ok(i)){
        printf("%d\n",i);
        return 0;
        }
    }