int main(void){
	int prime[500];
	int nold[500];
	int ptr1=2;
	int ptr2=0;
	int i,j,no;
	
	prime[0]=2;
	prime[1]=3;
	
	for (no=5; no<=1000;no+=2){
		int flag = 0;
		for(i = 1; prime[i]*prime[i]<=no; i++){
			if (no % prime[i] == 0){
				flag = 1;
				break;
			}
		}
		if (!flag){
			prime[ptr1++] = no;
		}
	}
	
	for (i = 1; i<=ptr1; i++){
		int flag = 0;
		for(j = 1; j<i-1; j++){
			if(prime[i] - 1 == prime[j] + prime[j+1]){
				flag = 1;
				break;
			}
		}
		if(flag){
			nold[ptr2++] = prime[i];
		}
	}
		int n,k;
		i=0;
		int count=0;
		scanf("%d %d",&n,&k);
		while(nold[i]<=n){
			count++;
			i++;
		}
		if (count<k) {
			printf("NO\n");
		}else {
			printf("YES\n");
		}
	
		
	return(0);
}