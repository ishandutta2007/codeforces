 #include<bits/stdc++.h>
using namespace std;

inline void swap(int &a , int &b){
	int t = a;
	a = b;
	b = t;
}

int appear[1001] , Ed[1001][2];

deque < int > q;

int main()
{
	int N , cntEd = 0;
	scanf("%d" , &N);
	for(int i = 1 ; i < N ; i++){
		int a , b;
		scanf("%d%d" , &a , &b);
		if(a > b)
			swap(a , b);
		if(b != N){
			printf("NO");
			return 0;
		}
		appear[a]++;
	}
	for(int i = 1 ; i < N ; i++)
		if(!appear[i])
			q.push_back(i);
		else{
			int dir = i;
			for(int j = 1 ; j < appear[i] ; j++){
				if(q.empty()){
					printf("NO");
					return 0;
				}
				Ed[++cntEd][0] = dir;
				dir = Ed[cntEd][1] = q.front();
				q.pop_front();
			}
			Ed[++cntEd][0] = dir;
			Ed[cntEd][1] = N;
		}
	printf("YES\n");
	for(int i = 1 ; i < N ; i++)
		printf("%d %d\n" , Ed[i][0] , Ed[i][1]);
 	return 0;
}