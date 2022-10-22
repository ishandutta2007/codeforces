#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=5e3+10;
int val(int x){
    cout<<"? "<<x<<endl;
    cin>>x;
    return x;
}
bool gr(int x){
    if(x>1000000000)return 0;
    cout<<"> "<<x<<endl;
    cin>>x;
    return x;
}
int main(){
    srand(time(0));
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i,cur;
    //cout<<__gcd(0,0);
    cin>>n;
    cur=-1;
    for(i=1<<29;i;i>>=1){
        if(gr(cur+i))cur+=i;
    }
    int big=cur+1;
    int g=0;
    for(i=0;i<30;i++)g=__gcd(g,abs(big-val(rand()*rand()%n+1)));
    cout<<"! "<<big-g*(n-1)<<" "<<g<<endl;
}