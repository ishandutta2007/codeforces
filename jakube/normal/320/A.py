state = 0
states = {
    0: {"1": 1}, 
    1: {"1": 1, "4": 2}, 
    2: {"1": 1, "4": 0}}

for c in input():
    state = states[state].get(c, -1)
    if state == -1:
        print("NO")
        break
else:
    print("YES")