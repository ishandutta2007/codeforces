import sys
n = int(sys.stdin.readline())
a = sys.stdin.readline().split()
min = 100
for i in range(n):
  a[i] = int(a[i])
  if a[i] < min:
    min = a[i]
  
count = 0
for x in a:
  if x == min:
    count += 1
    
if count > n / 2:
  print('Bob')
else:
  print('Alice')