buf = input().split(" ")

n = int(buf[0])
k = int(buf[1])

wyn = 0

buf = input().split(" ")
for i in range(n):
  if int(buf[i])>0 and int(buf[i])>=int(buf[k-1]):
    wyn += 1
    
print(wyn)