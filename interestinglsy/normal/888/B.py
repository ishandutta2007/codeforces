s=input()[:0]+input()
print(min(s.count('L'),s.count('R'))*2+min(s.count('U'),s.count('D'))*2)