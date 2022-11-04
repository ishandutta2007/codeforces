#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>


int main(){
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++){
		int n;
		std::cin >> n;
		long long min = 1e11;
		long long max = 0;
		long long bef = -2;
		long long maxDiff = 0;
		for (int j = 0; j < n; j++){
			int num;
			std::cin >> num;
			if (bef == -2){
				bef = num;
				continue;
			}
			if (bef == -1){
				if (num == -1)
					continue;
				if (num > max)
					max = num;
				if (num < min)
					min = num;
			} else{
				if (num == -1){
					if (bef > max)
						max = bef;
					if (bef < min)
						min = bef;
				} else if (abs(bef - num) > maxDiff){
					maxDiff = abs(bef - num);
				}
			}
			bef = num;
		}
		if (max == 0 && min == 1e11)
			min = 0;
		long long mid = (min + max) / 2;
		long long dist = max - mid > mid - min ? max - mid : mid - min;
		long long actDist = maxDiff > dist ? maxDiff : dist;
		printf("%lld %lld\n", actDist, mid);
	}
}