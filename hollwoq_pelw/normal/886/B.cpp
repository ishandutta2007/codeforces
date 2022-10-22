#include<bits/stdc++.h>
int n,i,l[200005];int main(){for(scanf("%d",&n);n--;)scanf("%d",&i),l[i]=n+1;printf("%d",std::max_element(l,l+200005)-l);}