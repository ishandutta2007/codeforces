#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>

int n,top;
std::multiset<long long>set[101];
long long tem[101];
struct string{
	int cnt[26],len;
	long long hash;
	void gethash(){
		hash=1;
		for(int i=0;i<26;i++)hash=(2333ll*hash+113ll*cnt[i])%(10007ll*998244353);
	}
	void ini(){
		memset(this,0,sizeof *this);
	}
}num[20001],ans;
bool cmp(string a,string b){return a.len>b.len;}
char str[101],fin[101];
void query(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	top=((r-l+1)*(r-l+2))>>1;
	for(int i=1;i<=top;i++){
		scanf("%s",str+1);
		num[i].ini();
		for(int j=1;str[j];j++)++num[i].len,++num[i].cnt[str[j]-'a'],str[j]=0;
	}
}
void get(int l,int r){
	query(l,r);
	for(int i=1;i<=r-l+1;i++)set[i].clear();
	for(int i=1;i<=top;i++){
		num[i].gethash();
		set[num[i].len].insert(num[i].hash);
	}
	query(l+1,r);
	for(int i=1;i<=top;i++){
		num[i].gethash();
		set[num[i].len].erase(set[num[i].len].find(num[i].hash));
	}
	ans.ini();
	for(int i=1;i<=r-l+1;i++){
		for(int j=0;j<26;j++){
			++ans.cnt[j];
			ans.gethash();
			if(ans.hash==*set[i].begin()){fin[l+i-1]=j+'a';break;}
			--ans.cnt[j];
		}
	}
}
char out1(int l){
	printf("? %d %d\n",l,l);fflush(stdout);scanf("%s",str+1);
	return str[1];
}
int main(){
	scanf("%d",&n);
	if(n==1){printf("! %c",out1(1));fflush(stdout);return 0;}
	if(n==2){printf("! %c%c\n",out1(1),out1(2));fflush(stdout);return 0;}
	get(1,(n+1)>>1);
	query(1,n);
	std::sort(num+1,num+top+1,cmp);
	ans=num[1];
	for(int i=n-1,now=2;i;i--){
		set[0].clear();
		while(num[now].len==i){
			num[now].gethash();
			set[0].insert(num[now++].hash);
		}
		for(int j=n;j>i;j--){
			for(int k=j+1;k<=n;k++)--num[1].cnt[fin[k]-'a'];
			for(int k=1;k+i<=j;k++)--num[1].cnt[fin[k]-'a'];
			num[1].gethash();
			set[0].erase(set[0].find(num[1].hash));
			for(int k=j+1;k<=n;k++)++num[1].cnt[fin[k]-'a'];
			for(int k=1;k+i<=j;k++)++num[1].cnt[fin[k]-'a'];
		}
		for(int j=0;j<26;j++){
			--ans.cnt[j];
			ans.gethash();
			if(ans.hash==*set[0].begin()){fin[i+1]=j+'a';break;}
			++ans.cnt[j]; 
		}
	}
	printf("! %s",fin+1);
	fflush(stdout);
}