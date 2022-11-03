#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n,m,k,a,b,c;
	scanf("%d%d%d",&n,&m,&k);
	int *row_ord,*col_ord,*row_num,*col_num,**arr;
	row_ord = new int[n];
	row_num = new int[n];
	col_ord = new int[m];
	col_num = new int[m];
	arr = new int*[n];
	for(int i=0;i<n;i++){
		row_ord[i]=-1;
		row_num[i]=-1;
	}
	for(int i=0;i<m;i++){
		col_ord[i]=-1;
		col_num[i]=-1;
	}
	for(int i=0;i<k;i++){
		scanf("%d%d%d",&a,&b,&c);
		b--;
		if(a==1){
			row_ord[b]=i;
			row_num[b]=c;
		}else{
			col_ord[b]=i;
			col_num[b]=c;
		}
	}
	map<int,pair<int,int> > mp;
	for(int i=0;i<n;i++){
		arr[i] = new int[m];
		for(int j=0;j<m;j++){
			arr[i][j]=0;
		}
		mp[row_ord[i]]=make_pair(1,i);
	}
	for(int i=0;i<m;i++){
		mp[col_ord[i]]=make_pair(2,i);
	}
	mp.erase(-1);
	for(auto it: mp){
		if(it.second.first==1){
			for(int i=0;i<m;i++){
				arr[it.second.second][i]=row_num[it.second.second];
			}
		}else{
			for(int i=0;i<n;i++){
				arr[i][it.second.second]=col_num[it.second.second];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}