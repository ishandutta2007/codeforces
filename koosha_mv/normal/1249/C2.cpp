#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
vector<int> b;
unsigned long long int f(unsigned long long int x){
	if(x==0)
		return 1;
	if(x%3>1)
		return 0;
	return f(x/3);
}
unsigned long long int t(unsigned long long int x){
	int q=0;
	while(x!=0){
		x=x/3;
		q++;
	}
	return q;
}
unsigned long long int t2(unsigned long long int x){
	if(x==0){
		b.push_back(0);
		return 0;
	}
	b.push_back(x%3);
	x/=3;
	t2(x);
}
int main(){
	unsigned long long int q,n;
	cin>>q;
	for(unsigned long long int i=0;i<q;i++){
		cin>>n;
		if(f(n)==1)
			cout<<n<<endl;
		else{
			unsigned long long int y=1,y2=1,m,s;
			b.clear();
			t2(n);
			//for(int pp=0;pp<b.size();pp++){
			//	cout<<b[pp]<<" ";
			//}
			for(int i2=0;i2<b.size();i2++){
				if(b[i2]>1)
					m=i2;
			}
			for(int i2=m+1;i2<b.size();i2++){
				if(b[i2]==0){
					s=i2;
					break;
				}
			}
			if(s==t(n)){
				for(int s3=0;s3<s;s3++)
					y*=3;
				cout<<y<<endl;
			}
			else{
				for(int s3=0;s3<s;s3++)
					y*=3;
				for(int s3=s+1;s3<b.size();s3++){
					y2=1;
					if(b[s3]==1){
						for(int s5=0;s5<s3;s5++)
							y2*=3;
						y+=y2;
					}
				}
				cout<<y<<endl;
			}
		}
	}
}