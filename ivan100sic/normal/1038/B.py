n=int(input())
if n<=2:
 print('No')
else:
 print("Yes")
 print(1,n)
 print(n-1, ' '.join(list(map(str,range(1,n)))))