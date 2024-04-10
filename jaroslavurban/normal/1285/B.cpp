#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>


#define ll long long int

int main(){
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++){
		ll adel = 0;
		ll n_adel = 0;
		ll adel_max = -1e10;
		ll n_adel_max = 0;
		ll yasser = 0;
		ll nc = 0;
		std::cin >> nc;
		for (int j = 0; j < nc; j++){
			ll cake;
			std::cin >> cake;
			adel += cake;
			if (adel > 0){
				n_adel++;
				if (adel > adel_max){
					adel_max = adel;
					n_adel_max = n_adel;
				}
			}
			else{
				n_adel = 0;
				adel = 0;
			}
			yasser += cake;
		}
		if (n_adel_max && (yasser > adel_max || n_adel_max == nc))
			printf("YES\n");
		else
			printf("NO\n");
	}
}