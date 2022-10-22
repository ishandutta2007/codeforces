    #include <bits/stdc++.h>

    using namespace std;
    typedef long long ll;
    int n,k,x,h2,h4,h1,ans;
    int main()
    {
        ios::sync_with_stdio(0);
    cin>>n>>k;

    for(int i=0;i<k;i++)
    {
        cin>>x;
        h4+=x/4;
        x%=4;
        h2+=x/2;
        x%=2;
        h1+=x;

    }

    if(h4>n){h2+=2*(h4-n);h4=n;}
    while(n>h4&&h1>0&&h2>0){h4++;h1--;h2--;}
    while(n>h4&&h1>1){h4++;h1-=2;}
h2+=h1;
while(n>h4+1&&h2>2*n){h4+=2;h2-=3;}
while(n>h4&&h2>2*n){h4++;h2--;}
if(h2>2*n)cout<<"NO";
else cout<<"YES";
        return 0;
    }