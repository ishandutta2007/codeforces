n = int(input())
buf = input()

wyn = 0
for i in range(1,n):
  if buf[i]==buf[i-1]:
    wyn += 1
    
print(wyn)