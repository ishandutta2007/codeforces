#include <cstdio>
#include <vector>
#include <algorithm>

long long orig[8000010],lim,h,q,add[8000010];
std::vector<std::pair<long long,long long> >vec1,vec2;
int main(){
	scanf("%I64d%I64d",&h,&q);
	long long I,ans,L,R;
	for(int i=1;i<=q;i++){
		scanf("%I64d%I64d%I64d%I64d",&I,&L,&R,&ans);
		for(int j=1;j<=h-I;j++)
			L<<=1,(R<<=1)++;
		if(ans)vec1.push_back(std::make_pair(L,R+1));
		else vec2.push_back(std::make_pair(L,R+1));
		orig[(i<<1)-1]=L;
		orig[i<<1]=R+1;
	}
	orig[(q<<1)+1]=1ll<<(h-1ll);
	orig[(q<<1)+2]=(1ll<<h)-1ll;
	std::sort(orig+1,orig+((q+1)<<1)+1);
	lim=std::unique(orig+1,orig+((q+1)<<1)+1)-orig-1;
	orig[lim+1]=orig[lim]+1;
	for(auto it=vec1.begin();it!=vec1.end();++it){
		++add[std::lower_bound(orig+1,orig+lim+1,it->first)-orig];
		--add[std::lower_bound(orig+1,orig+lim+1,it->second)-orig];
	}
	for(auto it=vec2.begin();it!=vec2.end();++it){
		++add[1];
		--add[std::lower_bound(orig+1,orig+lim+1,it->first)-orig];
		++add[std::lower_bound(orig+1,orig+lim+1,it->second)-orig];
	}
	long long count=0,start=-1;
	for(int i=1;i<=lim;i++){
		add[i]+=add[i-1];
		if(add[i]==q&&orig[i]<(1ll<<h)){
			count+=orig[i+1]-orig[i];
			start=orig[i];
		}
	}
	if(!count)puts("Game cheated!");
	else if(count>1)puts("Data not sufficient!");
	else printf("%I64d\n",start);
}