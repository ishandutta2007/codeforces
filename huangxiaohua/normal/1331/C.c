#include<stdio.h>
int sb[7]={0},a;

int main()
{
scanf("%d",&a);
if(a>=32){a-=32;sb[6]=1;
}
if(a>=16){a-=16;sb[5]=1;
}
if(a>=8){a-=8;sb[4]=1;
}
if(a>=4){a-=4;sb[3]=1;
}
if(a>=2){a-=2;sb[2]=1;
}
if(a>=1){a-=1;sb[1]=1;
}
printf("%d",sb[1]*16+sb[2]*2+sb[3]*8+sb[4]*4+sb[5]*1+sb[6]*32);
return 0;
}