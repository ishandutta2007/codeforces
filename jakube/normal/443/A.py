line = raw_input()

cnt = 0
for i in range(ord('a'), ord('z')+1):
    if chr(i) in line:
        cnt+=1
print cnt