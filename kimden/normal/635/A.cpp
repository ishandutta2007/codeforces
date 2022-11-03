#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int r,c,n,k,x,y,a,ans;
	bool **arr;
	scanf("%d%d%d%d",&r,&c,&n,&k);
	arr=new bool* [r];
	for(int i=0;i<r;i++){
		arr[i]=new bool[c];
		for(int j=0;j<c;j++){
			arr[i][j]=false;
		}
	}
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		arr[x-1][y-1]=true;
	}
	ans=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			for(int q=i;q<r;q++){
				for(int w=j;w<c;w++){
					a=0;
					for(int g=i;g<=q;g++){
						for(int h=j;h<=w;h++){
							if(arr[g][h])
								++a;
						}
					}
					if(a>=k)
						++ans;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}