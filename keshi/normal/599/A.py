a,b,c=map(int,input().split())
print(min(a+b+c,a+a+b+b,a+a+c+c,b+b+c+c))