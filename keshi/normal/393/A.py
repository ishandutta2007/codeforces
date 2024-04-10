s=input()
print(min(max((s.count('n')-1)//2,0),s.count('e')//3,s.count('t'),s.count('i')))