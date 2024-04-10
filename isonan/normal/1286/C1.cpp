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
int main(){
	scanf("%d",&n);
	if(n==1){printf("? 1 1\n");fflush(stdout);scanf("%s",str+1);printf("! %s",str+1);fflush(stdout);return 0;}
	get(1,n);
	printf("! %s",fin+1);
	fflush(stdout);
}