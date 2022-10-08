n = int(input())
x = 1
t = 0
res = 0

for i in range(1,201):
   t += x
   x += i+1
   if n >= t:
      res = max(res, i)
   
print(res)