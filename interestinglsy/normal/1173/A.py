x,y,z = map(int,input().split())
d = x-y
if d < -z: print('-')
elif d > z: print('+')
elif d == 0 and z == 0: print('0')
else: print('?')