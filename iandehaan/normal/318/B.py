inp = input()
out = 0
heavys = 0
for i in range(len(inp)-4):

    if inp[i:i+5] == "heavy":
        heavys += 1
    elif inp[i:i+5] == "metal":
        out += heavys
print(out)