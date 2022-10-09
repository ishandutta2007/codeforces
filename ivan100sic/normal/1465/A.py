n=int(input())
for i in range(n):
 l=int(input())
 s=input()
 e=0
 while e<l:
  if s[l-e-1] == ')':
   e+=1
  else:
   break
 if e>l-e:
  print('Yes')
 else:
  print('No')