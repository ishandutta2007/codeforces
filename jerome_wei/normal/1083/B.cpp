#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

struct Node{
	int ch[2],suml,sumr,dep;
}t[N*2];
int cnt=1,root=1;
int n,k;
char L[N],R[N];
void ins(char *s,int len,int tpe){
	int x=root;
	int dp=0;
	for(int i=1;i<=len;i++){
		int c=s[i]-'a';
		if(t[x].ch[c]) x=t[x].ch[c];
		else x=t[x].ch[c]=++cnt;
		if(tpe) t[x].sumr=1;
		else t[x].suml=1;
//		cout << x <<" "<< t[x].suml << " " << t[x].sumr << dp+1 <<endl;
		t[x].dep = ++dp;
	}
}
typedef long long ll;
ll ans=0;

ll tpe[N];

int main()
{
	cin >> n >> k;
	scanf("%s%s",L+1,R+1);
	ins(L,n,0);
	ins(R,n,1);
	if(k==1){
		cout<<n<<endl;
		return 0;
	}
	ans += cnt-1;
	for(int i=2;i<=cnt;i++){
		if(!t[i].sumr && !t[i].ch[1]) ++tpe[n-t[i].dep];
		if(!t[i].suml && !t[i].ch[0]) ++tpe[n-t[i].dep];
	}
	//cout << ans << endl;
	k-=2;
	ll S=0;	
	for(int i=n;i&&k>0;i--){
		ll Sum=min((ll)k,tpe[i]+S);
		ans += Sum*i;
		//cout<<i<<" "<<Sum<<"!"<<endl;
		k-=Sum;
		S+=Sum;
	}
	cout<<ans<<endl;
}