#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a,b,ab,ba,num[666],lst,cur,tmp;
char s[500500];
vector<int> v1,v2;

void chk(int l,int r){
	//printf("a%d %d %c %c\n",l,r,s[l],s[r]);
	if((r-l+1)&1){
		tmp+=(r-l+1)/2;
		return;
	}
	if(s[l]=='A'&&s[r]=='B'){
		v2.push_back((r-l+1)/2);
	}
	else{
		v1.push_back((r-l-1)/2);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		v1.clear();
		v2.clear();
		cin>>a>>b>>ab>>ba>>s+1;
		n=strlen(s+1);
		num['A']=num['B']=0;
		num['A']-=a+ab+ba;
		num['B']-=b+ab+ba;
		for(i=1;i<=n;i++){
			num[s[i]]++;
		}
		if(num['A']||num['B']){
			//printf("cnm%d %d\n",num['A'],num['B']);
			cout<<"NO\n";continue;
		}
		cur=0;
		tmp=0;
		lst=1;
		for(i=1;i<=n+1;i++){
			if(s[i]=='A'&&s[i+1]=='B')cur++;
			if(i==n+1||s[i]==s[i-1]){
				chk(lst,i-1);
				lst=i;
			}
		}
		//printf("NMSL%d %d %d %d\n",cur,tmp,ab,ba);
		ab-=cur;
		if(ab>0){
			cout<<"NO\n";continue;
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		reverse(v2.begin(),v2.end());
		for(auto i:v1){
			if(ab+i>0){
				ba+=ab;
				ab=0;
				break;
			}
			ab+=i;
			ba-=i;ba--;
		}
		if(ab+tmp>0){
			ba+=ab;
			ab=0;
		}
		else{
			ba-=tmp;
			ab+=tmp;
		}
		for(auto i:v2){
			//cout<<i<<' '<<ab<<endl;
			if(!ab)break;
			ab++;i--;
			if(ab+i>0){
				ba+=ab;
				ab=0;
				break;
			}
			ab+=i;
			ba-=i;
		}
		cout<<((ab<=0&&ba<=0)?"YES":"NO")<<'\n';
	}
}