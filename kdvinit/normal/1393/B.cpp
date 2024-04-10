/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    int n,m=1e5,q;
    cin>>n;

    int freq[m+1]={0},cnt4=0,cnt2=0;
    for(int i=1;i<=n;i++) { int x; cin>>x; freq[x]++; }

    for(int i=1;i<=m;i++)
    {
        int x=freq[i];
        int y=(x/4);
        cnt4+=y;
        cnt2+=((x%4)/2);
    }

    cin>>q;
    for(int i=1;i<=q;i++)
    {
        char z;
        int y;
        cin>>z>>y;
        if(z=='+')
        {
            int x=freq[y];
            if(x%4==1) cnt2++;
            if(x%4==3) { cnt2--; cnt4++; }
            freq[y]++;
        }
        else
        {
            int x=freq[y];
            if(x%4==0) { cnt2++; cnt4--; }
            if(x%4==2) cnt2--;
            freq[y]--;
        }

        if(cnt4>=2) cout<<"YES"<<endl;
        else if(cnt4==1 && cnt2>=2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	t=1;
	while(t--) solve();
	return 0;
}