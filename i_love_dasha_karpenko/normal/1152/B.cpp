#include <bits/stdc++.h>

using namespace std;
#define DIM 10008
#define INF 10E16
#define MAXN 10000007
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef ll arr[DIM];
ll x,M=0;
queue<ll> Q;
int main()
{
    //freopen("input.txt","r",stdin);

    cin>>x;
    ll r = 1,a,l,h,flag=0;
    a = x;

    while(1){
        a = x;
        r = 0;
        l = -1;
        while(a>1){
            if (a%2==0)l = r;
            r++;
            a/=2;
        }
        if (l==-1){
            break;
        }
        l++;
        Q.push(l);
        h = pow(2,l)-1;
        x^=h;
        a = x;
        flag = 0;
        while(a>1){
            if (a%2==0){flag = 1;break;}
            a/=2;
        }
        if (flag==0){
            M = 1;
            break;
        }
        x++;
        a = x;
        flag = 0;

    }
    cout<<Q.size()*2-M<<endl;
    while(!Q.empty()){
        cout<<Q.front()<<' ';
        Q.pop();
    }

}